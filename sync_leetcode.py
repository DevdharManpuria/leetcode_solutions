import os
import json
import requests
import re
import time

# Load config
with open('config.json', 'r') as f:
    config = json.load(f)

HEADERS = {
    'cookie': config['cookie'],
    'x-csrftoken': config['csrf_token'],
    'referer': 'https://leetcode.com',
    'origin': 'https://leetcode.com',
    'content-type': 'application/json',
}

GRAPHQL_QUERY = '''
query recentAcSubmissions {
  recentAcSubmissionList(limit: 20) {
    id
    title
    titleSlug
    timestamp
  }
}
'''

def fetch_submissions():
    url = 'https://leetcode.com/graphql/'
    payload = {
        'operationName': 'recentAcSubmissions',
        'query': GRAPHQL_QUERY,
        'variables': {}
    }
    res = requests.post(url, headers=HEADERS, json=payload)
    if res.status_code != 200:
        print(f"❌ Failed to fetch submissions: {res.status_code}")
        print(res.text)
        return []
    data = res.json().get("data", {})
    return data.get("recentAcSubmissionList", [])

def fetch_code(title_slug):
    url = f"https://leetcode.com/problems/{title_slug}/submissions/"
    res = requests.get(url, headers=HEADERS)
    m = re.search(r'submissionCode:\s*\'(.*?)\',\\n', res.text, re.DOTALL)
    if not m:
        return None
    return bytes(m.group(1), "utf-8").decode("unicode_escape")

def get_numbered_filename(index, title_slug):
    return f"{index:04d}-{title_slug}.py"

def save(index, title, title_slug, code):
    os.makedirs("solutions", exist_ok=True)
    filename = get_numbered_filename(index, title_slug)
    path = os.path.join("solutions", filename)
    if os.path.exists(path):
        print(f"⏩ Already exists: {filename}")
        return
    with open(path, "w", encoding="utf-8") as f:
        f.write(f"# {title}\n\n{code}")
    print(f"✅ Saved: {filename}")

def main():
    submissions = fetch_submissions()
    if not submissions:
        print("❌ No submissions fetched.")
        return

    for i, sub in enumerate(submissions, 1):
        title = sub['title']
        title_slug = sub['titleSlug']
        print(f"⬇ Fetching {title_slug}...")
        code = fetch_code(title_slug)
        if code:
            save(i, title, title_slug, code)
        else:
            print(f"⚠️ Code not found for {title_slug}")
        time.sleep(2)  # Respect LeetCode rate limiting

if __name__ == "__main__":
    main()
