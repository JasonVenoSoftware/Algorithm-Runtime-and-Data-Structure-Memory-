# Algorithm-Runtime-and-Data-Structure-Memory-
Algorithmic runtime analysis of pseudocode for various data structures

# What was the problem you were solving in the projects for this course?
This project involved creating the pseudocode to store the courses in a data structure that would allow me to quickly access them.  These courses included a course number (like "CSCI101"), a course name (like "Introduction to C++"), and 0-n prerequisites in the form of other course's numbers (ex. CSCI300 could have prerequisites of CSCI101 and CSCI200).  This project had me create a way to store the courses in a vector, a hash table, and a binary search tree, and then to complete a runtime analysis on each of them to determine which would be best.    

# How did you approach the problem? Consider why data structures are important to understand.
My first step was to create a way to store the courses in one structure (called "Course").  This would allow me to easily insert/delete them from data structures later on.  Next, I had to read the input file that contained the courses, and store them in Course structures.  Finally, I created functions for each of the three data structures that would be able to insert them, remove them, search for them, etc.  The important part here was to understand how each of the three data structures worked, and how to make the most use out of each of them.  For example, understanding how a binary search tree is set up would allow me to easily and correctly insert each node (Course) into  it.  

# How did you overcome any roadblocks you encountered while going through the activities or project?
As this was mostly just writing the pseudocode, the main roadblocks I ran into were theoretical, such as figuring out the most efficient way to read the file into the Course structure, or the fastest way to sort the vector.  Once I determined the best choice, it was as simple as writing out the steps to complete it.  

# How has your work on this project expanded your approach to designing software and developing programs?
The biggest thing I learned on this project is the value of writing pseudocode before coding.  This would've been a very complicated task to try to code by itself, and the pseudocode kept it organized and simple.  Also, I could really see the importance of breaking down a large problem and solving it one step at a time.  At first I was trying to figure out how to read the file directly into the three data structures, which proved to be extremely complicated.  Once I realized that I could simply read the file into a unique structure, it made the entire project much more straightforward.  

# How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
The most challenging part of this project was the fact that the courses didn't have the same amount of prerequisites.  This meant that I couldn't do perform the same operation on each course, and that I had to allow for the differences between the courses.  Though this was difficult, it makes for more useful code, because the courses don't have to be given to it in such a structured format.  This is something I will carry onto my future projects, as it will only make things easier for everyone.  
