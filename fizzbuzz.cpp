# include <simplecpp>

main_program {
  int n;
  cin >> n;

  // Your code starts from here -- DO NOT EDIT ANYTHING ABOVE
 // Loop from 1 to n
    for (int i = 1; i <= n; i++) {

        // Check for divisibility by both 3 and 5 first
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz" << endl;
        }
        // Check for divisibility by 3
        else if (i % 3 == 0) {
            cout << "Fizz" << endl;
        }
        // Check for divisibility by 5
        else if (i % 5 == 0) {
            cout << "Buzz" << endl;
        }
        // Otherwise, print the number itself
        else {
            cout << i << endl;
        }
  }
 // Your code ends here -- DO NOT EDIT ANYTHING BELOW
}
