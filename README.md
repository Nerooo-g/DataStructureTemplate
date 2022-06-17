Update: In the HashMap, which is based on the Directed Addressed, I adopted the linked list to store every element. And in the function of calculating the hash code, I just set the simple modulo number of size (type int, float, double, char), but in the string type, the hash code is calculated by each char.

For Binary Search Tree, there is not much to explain, except that in the function of removing nodes, I reflected on the implement method, which can be represented either the non-recursive or the recursive. By the way, the recursive method can avoid additional space overhead that the class won't create a member variable, the pointer named “parent”, to store the parent node. But overall, the non-recursive is better than the recursive.

In view of the time and space efficiency, I completed it with the non-recursive. But in the destructor, I adopted recursion for the sake of the great convenience.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

This is a C++ template repository for certain data structures, which will keep update if I am available.

Note: My test samples may not be enough, so welcome anyone to point the bugs. In addition, if you have any supporting advice, feel free to write on the issues.
