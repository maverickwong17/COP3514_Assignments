/*
project2.c
Due Date:   September 18, 2026
Name:       Maverick Wong
NetID:      U16095228
Description:
    ASCII Stream Transformer Project:
    Program to read a stream of characters from the user, classify the characters, convert them if needed to the appropriate type, print result, and repeat until user inputs '@' symbol to exit the program.
 */

 #include <stdio.h> // Include the standard input/output library

int main()
{
    // Define character variables to store user input abd the converted character
    char ch, converted;
    // Start a do-while loop to repeatedly prompt the user for input
    do
    {
        // Prompt the user to enter a character or '@' to exit
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character @ will exit the program):\n");
        ch = getchar();
        
        // Loop to process each character until '@' is entered
        while (ch != '@' )
        {
            // Ignore newline characters and break the loop if a newline is encountered
            if(ch == '\n')
            {
                printf("\n");
                break;
            }
            // Print the character and its ASCII value
            printf("\nYou typed: '%c' (ASCII %d)\n", ch, ch);
            
            if (ch >= 'A' && ch <= 'Z') // Check and convert uppercase letters to lowercase
            {
                printf("Class: Uppercase Letter\n");
                converted = ch + 'a' - 'A';
                printf("Converted to: '%c'\n", converted);
            }
            else if (ch >= 'a' && ch <= 'z') // Check and convert lowercase letters to uppercase
            {
                printf("Class: Lowercase Letter\n");
                converted = ch - ('a' - 'A');
                printf("Converted to: '%c'\n", converted);
            }
            else if (ch >= '0' && ch <= '9') // Check and convert digits to their 9's complement
            {
                printf("Class: Digit\n");
                converted = '9' - ch + '0';
                printf("Converted to: '%c'\n", converted);
            }
            else if (ch >= ' ' && ch <= '~') // Check for printable symbols and indicate no conversion
            {
                printf("Class: Printable Symbol\n");
                printf("No conversion done\n");
            }
            else // If no checks are true, classify as non-printable or extended ASCII and indicate no conversion
            {
                printf("Class: Non-printable or extended ASCII\n");
                printf("No conversion done\n");
            }
            // Read the next character from input
            ch = getchar();
        }

    } while (ch != '@');
    // Exit the program when '@' is entered
    return 0;
}