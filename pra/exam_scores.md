# Scores and Comments for `exam_1.c` to `exam_10.c`

`exam_7.c` is skipped as requested.

## `exam_1.c` - First Prime Numbers and Sum

Score: 8.5/10

Good:
- Correctly implements `is_prime`.
- Correctly prints the first `n` prime numbers.
- Correctly calculates and prints the sum.
- Matches the sample output for `n = 6`.

To improve:
- Check whether `scanf` succeeds.
- Do not use `unsigned n` if you want to reject negative input. With `%u`,
  negative input can become a very large unsigned number.
- The prime loop works, but it can be optimized by checking only up to
  `i <= n / i`.
- Add a newline after `"Invalid input"`.

## `exam_2.c` - Monthly Calendar

Score: 9/10

Good:
- Correctly validates `days` and `start`.
- Correctly prints the calendar header.
- Correctly aligns day `1` based on the starting weekday.
- Correctly starts a new line after Saturday.
- Matches the sample calendar layout.

To improve:
- Add a final newline when the month does not end on Saturday.
- Error messages should end with `\n`.
- The prompts are okay for interactive use, but the sample output in the
  exercise does not include prompts.

## `exam_3.c` - Reversed Cross Word

Score: 8.5/10

Good:
- Does not use `string.h`.
- Correctly implements a custom string length function.
- Correctly checks that the word length is odd.
- Correctly prints the vertical word and reversed horizontal word.
- Matches the sample output for `MANDARINO`.

To improve:
- Use a width limit in `scanf`, for example `scanf("%99s", s)`, to avoid
  writing past the end of the array.
- Check whether `scanf` succeeds.
- Use `MAX_WORD` consistently instead of hardcoding `100`.
- Add a newline after the error message for even-length input.

## `exam_4.c` - Student Grades, Average, and Mode

Score: 8/10

Good:
- Correctly defines the `Student` structure.
- Correctly converts numeric grades to letter grades.
- Correctly reads and prints the sample input.
- Correctly calculates the average for the sample.
- Correctly prints multiple mode grades.

To improve:
- Check whether reading `n` succeeds.
- Validate that `n > 0` and `n <= MAX_STUDENTS`.
- Avoid `Student students[n]` before validating `n`.
- Validate each grade before using `freq[students[i].grade - 18]`.
- If reading one student fails, stop instead of later printing uninitialized
  data.
- Remove the trailing space after the last mode value.

## `exam_5.c` - Merge Two Sorted Arrays and Search

Score: 8.5/10

Good:
- Correctly merges the sample sorted arrays.
- Correctly handles duplicate values during merge.
- Correctly implements recursive binary search for the sample.
- Correctly finds target `7` at index `6`.

To improve:
- Check whether all `scanf` calls succeed.
- Validate `n` and `m` before creating variable-length arrays.
- Use a simpler binary search base case: `if (left > right) return -1;`.
- Output wording does not exactly match the example. It prints
  `"Found 7 at index 6"` instead of `"Found at index 6"`.
- Add a newline after the final output.

## `exam_6.c` - Pointers, Array Reversal, and Matrix Sum

Score: 9/10

Good:
- Correctly implements `swap`.
- Correctly reverses the array.
- Correctly calculates the matrix sum.
- Matches the sample output.
- Uses functions with the requested signatures.

To improve:
- Check whether all `scanf` calls succeed.
- Validate `n`, `rows`, and `cols` before creating variable-length arrays.
- `reverse_pointer` works, but it mostly uses array indexing. To practice
  pointer arithmetic more directly, use expressions like `arr + i`.
- Add a newline after `"Matrix sum: ..."`.

## `exam_7.c` - Date Validation, Ordinal Day, and Next Date

Score: skipped

Comment:
- Skipped as requested because you already worked on this exercise yesterday.

## `exam_8.c` - Text Analysis Until EOF

Score: 8/10

Good:
- Correctly uses `getchar` until EOF.
- Correctly implements `is_letter` and `is_vowel`.
- Correctly counts words, vowels, and consonants for the sample input.
- Correctly ignores non-letter characters when counting vowels and consonants.

To improve:
- The longest word is not updated if the input ends while still inside a word.
  For example, input `hello` with no final newline prints longest length `0`.
- Remove the unused `str_len` function.
- The logic is good, but update `max_len` once more after the loop if
  `len_word > max_len`.

## `exam_9.c` - Recursive Pascal Triangle

Score: 8.5/10

Good:
- Correctly implements the recursive combination formula.
- Correctly prints Pascal's Triangle values.
- The output shape is close to the required triangle.
- Matches the sample values for `n = 5`.

To improve:
- Check whether `scanf` succeeds.
- Validate that `n > 0`; the question requires printing `"Invalid input"` for
  invalid values.
- Recursive combination repeats many calculations, so it becomes slow for
  larger `n`. This is acceptable for the recursive requirement, but worth
  knowing.
- Formatting is slightly different from the exact sample spacing.

## `exam_10.c` - Polynomial Structure

Score: 7/10

Good:
- Correctly defines the `Polynomial` structure.
- `init_poly` now clears all coefficients before setting the requested term.
- `coeff_at`, `degree`, `sum`, and `print_poly` mostly follow the requirement.
- The sample-style test output is close to correct.

To improve:
- `prod` has a serious out-of-bounds bug:

```c
result.coeff[i+j] += coeff_at(p1, i)*coeff_at(p2, j);
```

  Since `i` and `j` both go from `0` to `MAX_DEGREE`, `i + j` can be greater
  than `MAX_DEGREE`. That writes past the end of `result.coeff`.
- Add this guard inside the nested loops:

```c
if (i + j <= MAX_DEGREE){
    result.coeff[i+j] += coeff_at(p1, i) * coeff_at(p2, j);
}
```

- Check whether `init_poly` returns `NULL` in `main`.
- Check whether `prod` returns `NULL` before printing the result.
- The test in `main` is useful, but it does not test invalid exponent or degree
  overflow cases.

## Overall Comment

Most exercises compile and the sample behavior is generally good. The main
pattern to improve is input validation: check every `scanf`, validate array
sizes before creating arrays, and guard array indexes before writing into them.
