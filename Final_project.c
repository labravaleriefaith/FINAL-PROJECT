#include <stdio.h>

int main() {
    int choice, size, shape, rows;
    int i, j, s, tier, r, c, value;
    int count, length, left, right, isPalindrome;
    float grade, sum, average;
    char word[100];
    char again = 'Y';

    while (again == 'Y' || again == 'y') {

        /* ---------- MAIN MENU ---------- */
        printf("\n==============================\n");
        printf("      MAIN MENU\n");
        printf("==============================\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator\n");
        printf("4. Palindrome Checker\n");
        printf("Choose (1-4): ");
        scanf("%d", &choice);
        printf("\n");

        /* ---------- 1. PATTERN GENERATOR ---------- */
        if (choice == 1) {
            printf("Enter size/height: ");
            scanf("%d", &size);

            printf("\n1. Right Triangle\n");
            printf("2. Square\n");
            printf("3. Isosceles Triangle\n");
            printf("4. Inverted Right Triangle\n");
            printf("5. Christmas Tree\n");
            printf("Choose shape: ");
            scanf("%d", &shape);
            printf("\n");

            if (shape == 1) {                   /* Right Triangle */
                i = 1;
                while (i <= size) {
                    j = 1;
                    while (j <= i) {
                        printf("*");
                        j++;
                    }
                    printf("\n");
                    i++;
                }
            }
            else if (shape == 2) {              /* Square */
                i = 1;
                while (i <= size) {
                    j = 1;
                    while (j <= size) {
                        printf("*");
                        j++;
                    }
                    printf("\n");
                    i++;
                }
            }
            else if (shape == 3) {              /* Isosceles Triangle */
                i = 1;
                while (i <= size) {
                    s = 1;
                    while (s <= size - i) {
                        printf(" ");
                        s++;
                    }
                    j = 1;
                    while (j <= 2 * i - 1) {
                        printf("*");
                        j++;
                    }
                    printf("\n");
                    i++;
                }
            }
            else if (shape == 4) {              /* Inverted Right Triangle */
                i = size;
                while (i >= 1) {
                    j = 1;
                    while (j <= i) {
                        printf("*");
                        j++;
                    }
                    printf("\n");
                    i--;
                }
            }
            else if (shape == 5) {              /* Christmas Tree */
                tier = 0;
                while (tier < 3) {              /* 3 stacked triangles */
                    i = 1 + tier;
                    while (i <= size + tier) {
                        s = 1;
                        while (s <= (size + 2) - i) {
                            printf(" ");
                            s++;
                        }
                        j = 1;
                        while (j <= 2 * i - 1) {
                            printf("*");
                            j++;
                        }
                        printf("\n");
                        i++;
                    }
                    tier++;
                }
                i = 1;
                while (i <= 2) {                /* trunk: 2 rows */
                    s = 1;
                    while (s <= size) {
                        printf(" ");
                        s++;
                    }
                    printf("***\n");
                    i++;
                }
            }
            else {
                printf("Invalid shape choice.\n");
            }
        }

        /* ---------- 2. PASCAL'S TRIANGLE ---------- */
        else if (choice == 2) {
            printf("Enter number of rows: ");
            scanf("%d", &rows);
            printf("\n");

            r = 0;
            while (r < rows) {
                s = 1;
                while (s <= (rows - r - 1) * 2) {   /* spaces to center */
                    printf(" ");
                    s++;
                }
                value = 1;
                c = 0;
                while (c <= r) {
                    printf("%4d", value);
                    value = value * (r - c) / (c + 1);  /* next number */
                    c++;
                }
                printf("\n");
                r++;
            }
        }

        /* ---------- 3. GRADE CALCULATOR ---------- */
        else if (choice == 3) {

sum = 0;
            count = 1;
            while (count <= 4) {
                printf("Enter grade %d (Prelim, Midterm, Pre-Final, Final): ", count);
                scanf("%f", &grade);
                sum = sum + grade;
                count++;
            }
            average = sum / 4;
            printf("\nFinal Average: %.2f\n", average);
            if (average >= 1.0 && average <= 3.0) {
                printf("Status: PASS\n");
            }
            else if (average > 3.0 && average <=5.0){
                printf("Status: FAIL\n");
            }
        }

        /* ---------- 4. PALINDROME CHECKER ---------- */
        else if (choice == 4) {
            printf("Enter a single word: ");
            scanf("%s", word);

            length = 0;
            while (word[length] != '\0') {      /* count the letters */
                length++;
            }

            left = 0;
            right = length - 1;
            isPalindrome = 1;
            while (left < right && isPalindrome == 1) {
                if (word[left] != word[right]) {
                    isPalindrome = 0;
                }
                left++;
                right--;
            }

            if (isPalindrome == 1) {
                printf("\"%s\" is a palindrome.\n", word);
            }
            else {
                printf("\"%s\" is NOT a palindrome.\n", word);
            }
        }

        else {
            printf("Invalid choice. Please pick 1-4.\n");
        }

        /* ---------- TRY AGAIN ---------- */
        printf("\nDo you want to try another operation? (Y/N): ");
        scanf(" %c", &again);
    }

    printf("\nGoodbye!\n");
    return 0;
}
