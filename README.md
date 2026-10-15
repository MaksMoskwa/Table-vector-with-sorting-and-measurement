C++ Data Structures Performance Test
About the Project
This project compares the performance of three C++ data structures:

Array (t[])
Vector (std::vector)
List (std::list)
The program generates 100,000 random numbers for each data structure and measures how long it takes to perform three operations: inserting an element in the middle, sorting the elements, and removing an element from the middle.

The execution time is measured in microseconds using the C++ <chrono> library.

Features
Generates 100,000 random numbers for each data structure.
Inserts an element in the middle.
Sorts all elements.
Removes an element from the middle.
Measures the execution time of each operation separately.
Displays the results in the console.
Technologies Used
C++
Standard Template Library (STL)
<vector> and <list>
<algorithm>
<chrono>
How to Run
Clone this repository:
   git clone YOUR_REPOSITORY_URL
Navigate to the project directory.
Compile the program using a C++ compiler:
   g++ main.cpp -o benchmark -std=c++11
Run the program:
Windows:

   benchmark.exe
Linux / macOS:

   ./benchmark
Example Output
Tablica - wstawianie: 120 us
Tablica - sortowanie: 8500 us
Tablica - usuwanie: 90 us

Vector - wstawianie: 70 us
Vector - sortowanie: 7800 us
Vector - usuwanie: 50 us

Lista - wstawianie: 400 us
Lista - sortowanie: 18000 us
Lista - usuwanie: 350 us
The values above are examples. Actual execution times depend on your hardware, compiler, and system environment.

What Does This Project Demonstrate?
The project demonstrates how different data structures handle common operations and how their performance can be measured.

Array: Elements are stored in contiguous memory. Inserting and removing elements in the middle requires shifting elements.
Vector: Similar to an array, but its size can change dynamically. Inserting and removing elements in the middle may require shifting elements.
List: Elements are connected through links. Insertion and removal can be efficient when the correct iterator is available, but reaching the middle requires traversing the list.
Notes
The time required to generate random numbers is not included in the measurements.
For the list, insertion and removal measurements include the time needed to reach the middle.
The array has a fixed size, so insertion and removal are simulated by shifting elements.
Sorting is performed using std::sort() for the array and vector, and list::sort() for the list.
Benchmark results may vary between runs.
Purpose
This project was created for educational purposes to practice C++ programming, understand basic data structures, and learn how to measure execution time using <chrono>.

License
This project is available for educational and personal use.
