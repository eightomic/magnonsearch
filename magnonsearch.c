#include <stddef.h>

char magnonsearch_first(int *haystack, size_t haystack_length, int *needle,
                        size_t needle_length, size_t *position) {
  int tail_character;
  int mismatch_haystack_character;
  int mismatch_needle_character;
  size_t i;
  size_t j;
  size_t k;
  size_t l;
  size_t m;

  if (
    needle_length &&
    needle_length <= haystack_length
  ) {
    i = needle_length - 1;
    tail_character = needle[i];

    while (i < haystack_length) {
      if (haystack[i] != tail_character) {
        i++;
        continue;
      }

      j = i;
      k = needle_length - 1;
      l = i - k;
      m = 0;

      while (k > m) {
        if (haystack[l] != needle[m]) {
          j = l;
          k = m;
          break;
        }

        if (haystack[j] != needle[k]) {
          break;
        }

        j--;
        k--;
        l++;
        m++;
      }

      if (haystack[j] == needle[k]) {
        *position = (i - needle_length) + 1;
        return 1;
      }

      mismatch_haystack_character = haystack[j];
      mismatch_needle_character = needle[k];

      while (
        k &&
        i < haystack_length
      ) {
        i++;
        j++;
        k--;

        if (needle[k] == mismatch_haystack_character) {
          break;
        }
      }

      while (i < haystack_length) {
        if (haystack[j] == mismatch_needle_character) {
          break;
        }

        i++;
        j++;
      }
    }
  }

  return 0;
}
