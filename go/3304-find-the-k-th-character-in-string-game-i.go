func kthCharacter(k int) byte {
	length := 1
	ch := byte('a')
	for length < k {
		length *= 2
	}
	for length > 1 {
		half := length / 2
		if k > half {
			k -= half
			ch = (ch-'a'+1)%26 + 'a'
		}
		length = half
	}
	return ch
}