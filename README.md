# Improved-Food-Ordering-System

1. Using the C++ Compiler on your Computer
If you use Windows, you can install MinGW or Cygwin.
If you are using Linux, g++ is usually already installed. If not, you can install it with the command:

>> sudo apt-get install g++

If you are using macOS, you can install the Xcode Command Line Tools with the command:

>> xcode-select --install

Create a Source File:

2. Open a text editor (such as Notepad, Visual Studio Code, or another editor) and copy your C++ code into it.
>> Save the file with a .cpp extension, for example pesanan.cpp.

3. Open Terminal or Command Prompt:
>> Navigate to the directory where you saved the pesanan.cpp file.

4. Compile the Program:
Run the following command to compile the program:

>> g++ pesanan.cpp -o pesanan

This will produce an executable file named orders (or pesanan.exe on Windows).

5. Run the Program:
After successfully compiling, run the program with the command:

>> ./pesanan

In Windows, you can run it with:

>> pesanan.exe

Example of Input and Output:

Enter food orders (enter -1 to finish):
1 2
2 1
-1
Enter drink orders (enter -1 to finish):
1 3
2 2
-1
List of food ordered:
1. 2 Fried Chicken with a total price of Rp.24,000
2. 1 Grilled Chicken with a total price of Rp.13,000
Total price for food orders: Rp.37,000

List of drinks ordered:
1. 3 Mineral Water with a total price of Rp.12,000
2. 2 Sweet Ice Tea with a total price of Rp.10,000
Total price for drink orders: Rp.22,000

Total price for all orders: Rp.59,000

