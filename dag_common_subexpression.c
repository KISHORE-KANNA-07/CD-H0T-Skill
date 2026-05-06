#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSIONS 6
#define MAX_EXPRESSION_LENGTH 20

/*
 * Structure representing one unique DAG expression entry.
 * Expression_Frequency stores how many times the expression appears.
 * Is_Common_Subexpression is 1 when frequency is greater than 1, otherwise 0.
 */
struct DAGExpression {
    char Expression[MAX_EXPRESSION_LENGTH];
    int Expression_Frequency;
    int Is_Common_Subexpression;
};

/*
 * Searches for an expression in the unique expression list.
 * Returns the index if found, otherwise returns -1.
 */
int findExpressionIndex(struct DAGExpression expressionTable[], int uniqueCount, char expression[]) {
    int index;

    for (index = 0; index < uniqueCount; index++) {
        if (strcmp(expressionTable[index].Expression, expression) == 0) {
            return index;
        }
    }

    return -1;
}

/*
 * Builds a table of unique expressions and counts the frequency of each one.
 */
int buildExpressionFrequencyTable(
    char inputExpressions[][MAX_EXPRESSION_LENGTH],
    int totalExpressions,
    struct DAGExpression expressionTable[]
) {
    int inputIndex;
    int uniqueCount = 0;

    for (inputIndex = 0; inputIndex < totalExpressions; inputIndex++) {
        int existingIndex = findExpressionIndex(
            expressionTable,
            uniqueCount,
            inputExpressions[inputIndex]
        );

        if (existingIndex != -1) {
            expressionTable[existingIndex].Expression_Frequency++;
        } else {
            strcpy(expressionTable[uniqueCount].Expression, inputExpressions[inputIndex]);
            expressionTable[uniqueCount].Expression_Frequency = 1;
            expressionTable[uniqueCount].Is_Common_Subexpression = 0;
            uniqueCount++;
        }
    }

    return uniqueCount;
}

/*
 * Assigns the common subexpression flag based on expression frequency.
 */
void markCommonSubexpressions(struct DAGExpression expressionTable[], int uniqueCount) {
    int index;

    for (index = 0; index < uniqueCount; index++) {
        if (expressionTable[index].Expression_Frequency > 1) {
            expressionTable[index].Is_Common_Subexpression = 1;
        } else {
            expressionTable[index].Is_Common_Subexpression = 0;
        }
    }
}

/*
 * Displays the final result in a clean tabular format.
 */
void displayExpressionTable(struct DAGExpression expressionTable[], int uniqueCount) {
    int index;

    printf("Expression    Frequency    Is_Common_Subexpression\n");
    printf("---------------------------------------------------\n");

    for (index = 0; index < uniqueCount; index++) {
        printf("%-13s %-12d %d\n",
               expressionTable[index].Expression,
               expressionTable[index].Expression_Frequency,
               expressionTable[index].Is_Common_Subexpression);
    }
}

int main(void) {
    char inputExpressions[MAX_EXPRESSIONS][MAX_EXPRESSION_LENGTH] = {
        "a+b",
        "c*d",
        "a+b",
        "x-y",
        "c*d",
        "m/n"
    };

    struct DAGExpression expressionTable[MAX_EXPRESSIONS];
    int uniqueCount;

    uniqueCount = buildExpressionFrequencyTable(
        inputExpressions,
        MAX_EXPRESSIONS,
        expressionTable
    );

    markCommonSubexpressions(expressionTable, uniqueCount);
    displayExpressionTable(expressionTable, uniqueCount);

    return 0;
}
