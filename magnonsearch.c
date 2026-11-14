/*
  Copyright © 2026 Eightomic <eightomic@proton.me>

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <stddef.h>

char magnonsearch_first(unsigned char *haystack, size_t haystack_length,
                        unsigned char *needle, size_t needle_length,
                        size_t *position) {
  unsigned char needle_tail_character;
  unsigned char jump_character_a;
  unsigned char jump_character_b;
  size_t i = needle_length - 1;
  size_t j;
  size_t k;

  if (
    needle_length &&
    needle_length <= haystack_length
  ) {
    needle_tail_character = needle[i];

    while (i < haystack_length) {
      if (haystack[i] != needle_tail_character) {
        i++;
        continue;
      }

      j = i;
      k = needle_length - 1;

      while (k) {
        j--;
        k--;

        if (haystack[j] != needle[k]) {
          break;
        }
      }

      if (haystack[j] == needle[k]) {
        *position = (i - needle_length) + 1;
        return 1;
      }

      if ((k + 1) >= (needle_length - 1)) {
        i++;
        continue;
      }

      jump_character_a = haystack[j];
      jump_character_b = needle[k];

      while (
        k &&
        i < haystack_length
      ) {
        i++;
        j++;
        k--;

        if (needle[k] == jump_character_a) {
          break;
        }
      }

      jump_character_a = needle[k];
      k = needle_length - k - 1;

      while (i < haystack_length) {
        if (haystack[j] == jump_character_b) {
          if (
            haystack[i] != needle_tail_character ||
            haystack[i - k] != jump_character_a
          ) {
            i++;
            j++;
            continue;
          }

          break;
        }

        i++;
        j++;
      }
    }
  }

  return 0;
}
