/**
 * When the algorithm does not get involved with random, consider the worst case
 *
 * What about randomness?
 * - Sometime the worst case in randomness is inf, which is meaningless.
 * - User expectation or average.
 *
 * Ignore constant term
 *
 * Space complexity: Consider any EXTRA space requires in addition to the input space.
 *
 * Average:
 * - Time complexity for dynamic array extension is O(N), once averaged by the
 * number of element extended N / N = O(1)
 *
 * It could be inaccurate to estimate the time complexity solely by code structure.
 * Two layer of for loop does not necessarily mean it is N^2
 *
 */