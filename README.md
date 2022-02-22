# CS-210
Programming Languages: C++ 

This is Cody Gregory's Github Repository.

For this project for the Corner Grocer the main task at hand was to create a user interface that could disseminate a file and provide the user with their desired information.

To accomplish this task C++ was used as well as Python for its ability to process large amounts of data. I believe one of the strengths of this project lies in its organization. Separating the "Translator" code that converts the Python functions to C++ and the "Menu" functions that handle the interface, as well as the "Operations.py" Python code allows for an exceptionally straightforward and easy implentation of any future functions the user may desire. 

As the project stands I believe it to be pretty solid, with little to enhance. If I were to nitpick I would say there is probably some ways of initializing the Menu and Translator objects that could save some memory.

The most challenging part of this project would have to be the integration of Python to C++. Being that the code was supplied however I would say that prompting the user in C++ was very straightforward so that leaves the Python code as the most challenging, figuring out how to implement the given task and return a value that would work for the supplied "Translator" code. 

In the case of one of the Python functions a challenge I encountered was finding a clean way to remove duplicates from the "list" of strings I had taken from the the given file. My first idea was to sort the list and make a loop and compare two values, if the current item in the list was the same as the last item of the list I knew to ignore it, otherwise add it to another list and in turn I would have a new list without duplicates. This solution did accomplish the task, but I ran into an issue where the last item on the file did not have a newspace '\n' and resulted in a formatting error. To remedy this situation I consulted Python's documentation online to see if there were any convenient List() functions I could employ, before specifying my query even more and seaching for "How to remove duplicates from a list in Python." which lead me directly to the set() function that solved the whole issue in one simple line of code. 

Some of the skills that I have picked up and reinforce from working on this project would have to be:

  Python integration with C++. From troubleshooting my own install of Visual Studio on my PC I picked up a better understanding of PATHs, directories, and libraries. 
  
  Implementing header files. There was some confusion that definitely slowed me down, from accidentally breaking the 'one' rule where I initialized the constructor in the header out of habit by including {}'s. To the proper way of calling a class object from another file in C++ and utilizing pointers. 
