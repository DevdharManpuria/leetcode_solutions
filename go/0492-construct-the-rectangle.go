func constructRectangle(area int) []int {
    W := int(math.Sqrt(float64(area)))
    for area%W != 0 {
        W--
    }
    L := area / W
    return []int{L, W}
}