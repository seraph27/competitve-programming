def max_overlap_duration(intervals):
    # Step 1: Sort intervals by start time
    intervals.sort(key=lambda x: x[0])

    max_overlap = 0
    currentEarliestEnd = float('inf')

    # Step 3: Process intervals
    for s_i, f_i in intervals:
        if s_i <= currentEarliestEnd:
            # Overlap exists
            overlap = currentEarliestEnd - s_i
            if overlap > max_overlap:
                max_overlap = overlap
            currentEarliestEnd = min(currentEarliestEnd, f_i)
        else:
            # No overlap
            currentEarliestEnd = f_i

    return max_overlap
print(max_overlap_duration([(1, 4), (2, 6), (4, 9), (5, 7), (3, 10)]))
