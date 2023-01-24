// ----------------------------------------------------------------------------
// function prototypes

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lowerBound, int upperBound);

char inputCharOption(char validCharacters[]);

void inputCString(char* charString, int min, int max);

void displayFormattedPhone(const char* charString);

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);
