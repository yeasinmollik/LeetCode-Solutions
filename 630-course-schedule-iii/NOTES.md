Idea: Greedy using max-heap

1. Aim is to take maximum courses as long as each course taken ends before its last day
2. There is no restriction on when a course can be started, only ended
3. Sort the courses in increasing order of last days, i.e. the course that ends first will be ahead in the sorted array
4. Iterate through courses, take the current course and add its duration to a max-heap
5. If the total duration of courses yet exceeds the last day of the current course, then pop from the max-heap.
6. This action gives us an opportunity to swap a longer course with a shorter one with the added advantage of the new course ending earlier now.
7. Note that the shorter one could either be the current course or the previous course, whichever it would be, heap would take care of ejecting the longer one
8. This will be the duration of the longest course. Reduce it from total duration.
9. **This action is just swapping the longest course yet with the current course.**
10. Size of the heap will be the number of courses taken
