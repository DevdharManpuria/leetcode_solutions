func largestTriangleArea(points [][]int) float64 {
    maxArea := 0.0
	n := len(points)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				currentArea := area(points[i], points[j], points[k])
				if currentArea > maxArea {
					maxArea = currentArea
				}
			}
		}
	}
	return maxArea
}
func area(p1, p2, p3 []int) float64 {
	return 0.5 * math.Abs(float64(p1[0]*(p2[1]-p3[1])+p2[0]*(p3[1]-p1[1])+p3[0]*(p1[1]-p2[1])))
}