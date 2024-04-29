# Generate_Histogram

These programs are designed to be run in linux and a text file being used as the input.

histString.c
**Word Frequency Program**: The first program is designed to calculate the frequency of each unique word entered by the user. It reads words from the standard input until EOF (End Of File) is encountered. The words are stored in an array and the frequency of each unique word is calculated and stored in a histogram. The histogram is then sorted in descending order based on the frequency of each word. Finally, the program displays each word along with its frequency before and after sorting.

hist.c
**Score Frequency Program**: The second program is similar to the first one but it works with numerical scores instead of words. It reads scores from the user until EOF is encountered. The scores are stored in an array and the frequency of each unique score is calculated and stored in a histogram. The histogram is then sorted in descending order based on the frequency of each score. Finally, the program displays each score along with its frequency before and after sorting.

The main difference between these two programs is the type of data they work with. The first program works with strings (words), while the second program works with integers (scores). This difference is reflected in the data structures used (Histogram struct with a char* word in the first program and freq struct with an int score in the second program), the input reading functions (readWords reads strings in the first program and readScores reads integers in the second program), and the display functions (displayWords and displayHistogram output words and frequencies in the first program, while displayScores and displayHistogram output scores and frequencies in the second program). Other than these differences, the logic of the two programs is essentially the same. They both calculate the frequency of each unique item (word or score), sort the frequencies in descending order, and display the results.
