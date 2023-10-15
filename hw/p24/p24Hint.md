You can either make dpSolution a function or do it in main, your choice.

int dpSolution()

Parameters:

- int vector that holds the _length_ of each word in the input
- int width
- int height
- int size (holds size of of int vector)
- int count, holds the size of the text plus 1 (ex: "cosc 3320" would be 10)

The first thing we want to do is store all the repeating patterns
create an int vector, we will store our dp values in this
create 4 ints:

- index, this will hold which word we are on
- spaceTaken, holds how many spaces we've used in a line
- widthIndex, holds the index of the "row" we are on
- textCounter, holds how many texts have fit so far

The idea is that you want to parse words as long as the length of your current word is less than or equal to height-spacesTaken. If so, we want to increment spacesTaken by the size of the word (use the vector of lengths and index) + 1 (to account for a space). If index ever == size, increment textCounter by 1 and put it into your dp vector (use widthI). We will repeat this whole process until index reaches 0 again or widthI > width. (hint you'll use a while nested inside of a do while)
For efficiency however, you'll need to implement a way to shorten the amount of iterations by considering cases where the entire text can fit in a "row" once or multiple times. (hint use the count variable)

Once that process is done, that means you'll have the repeating pattern in your dp vector/array. All we have to do now is add our counter based on the previous array entries. To do this, create a single int that holds our current widthI. Now, while widthI < width, set dpArray[widthI] to textCounter plus the corresponding array entry. If you understand dynamic programming this part is fairly simple. If you're having trouble understanding this part, try and write out the second example in the assignment page, but with the width being 6 instead of 3. You'll see the pattern we've been working for.

Lastly, return dpArray[width-1]
