# push_swap

## Project workflow

<ul>
  <li><a href="#Mandatory part">Mandatory part</a></li>
  <li><a href="#Bonus part">Bonus part</a></li>
  <li><a href="#Results">My results</a></li>
</ul>

### <h3 id="Mandatory part">Mandatory part</h3>
In this project, I implemented stack sorting logic using a temporary stack 'b'. The stack should be sorted in the **least possible number of actions**. Our arguments in the stack are integer numbers which we pass when running the program and **they can't repeat**. The lowest number should be at the top of the first stack 'a', with numbers in ascending order. We can only use the following restricted actions:

<ul>
<li>sa - swap the top 2 elements in stack 'a'.</li>
<li>sb - swap the top 2 elements in stack 'b'.</li>
<li>ss - swap the top 2 elements in both stacks at the same time.</li>
<li>pa - push the top element from stack 'a' to stack 'b'.</li>
<li>pb - push the top element from stack 'b' to stack 'a'.</li>
<li>ra - rotate stack 'a' (the last element becomes the first).</li>
<li>rb - rotate stack 'b' (the last element becomes the first).</li>
<li>rr - rotate both stacks at the same time (the last elements become the first).</li>
<li>rra - rotate stack 'a' in the reverse direction (the first element becomes the last).</li>
<li>rrb - rotate stack 'b' in the reverse direction (the first element becomes the last).</li>
<li>rrr - rotate both stacks in the reverse direction at the same time (the first elements become the last).</li>
</ul>

I have a special solution for cases when we have only 3 or fewer numbers. Otherwise, I transfer numbers from stack 'a' to stack 'b' until stack 'a' has 3 numbers remaining.

I decided to pass numbers to stack 'b' to their suitable positions. This means I create stack 'b' and pass numbers in descending order because stack 'a' should be in ascending order, and I can only push the last element from the stack.

To achieve the least possible number of instructions, I created a **pre-calculation logic** that calculates the number of actions for each number.

My calculation logic compares each element in stack 'a' with each element in stack 'b' and finds a suitable position for it. It should be placed above the highest number in stack 'b' that is less than the number from stack 'a'. It calculates how many times and in which direction these stacks should be rotated. After this calculation, I compare the sum of each pair of numbers and choose the lowest value, saving the index of that pair.

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/1.png" alt="Picture 1"/>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/2.png" alt="Picture 2"/>
</p>

After that, I perform the actual actions and push a number from stack 'a' to stack 'b'. As I mentioned, I repeat these actions until stack 'a' has a size of 3. When the size of stack 'a' equals 3, I check if the highest number is at the top of stack 'b'. If not, I rotate this stack as many times as needed.

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/3.png" alt="Picture 3"/>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/4.png" alt="Picture 4"/>
</p>

![Picture 5](https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/5.png)

Then I run the small_sort function for the remaining 3 numbers in stack 'a'.

![Picture 6](https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/6.png)

Finally, I push numbers from stack 'b' to stack 'a' to their suitable places. They must be pushed above the lowest number in stack 'a' that is greater than a number from stack 'b'. When the size of stack 'b' is 0, I check if the lowest element in stack 'a' is at the top. If not, I rotate this stack until it is.

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/7.png" alt="Picture 7"/>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/8.png" alt="Picture 8"/>
</p>

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/9.png" alt="Picture 9"/>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/10.png" alt="Picture 10"/>
</p>

![Picture 11](https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/11.png)

At the end, I **free all remaining memory**.

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/push_swap%20gif.gif" alt="Picture 12"/>
</p>

### <h3 id="Bonus part">Bonus part</h3>

The bonus part requires implementing the **checker_OS** program. This program receives a list of numbers (just like push_swap) and then a list of instructions one by one from the standard input. It must check a few conditions:

<ul>
<li>The stack 'a' is sorted after the list of instructions.</li>
<li>The stack 'b' is empty.</li>
</ul>

The logic is quite simple: first, you convert your arguments (numbers) and put them in the stack. Then, you receive the list of instructions, check each instruction (there can be invalid input or instructions that don't exist or have extra characters), and perform those instructions on the stack. After that, you just need to check if stack 'a' is sorted and print **"OK"** or **"KO"**.
Of course, you should always remember to manage memory and free it in all possible situations.

### <h3 id="Results">My results</h3>

This logic earned me the highest grade in that project, with results that were below the lowest threshold of instructions.

<p>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/test%20100.jpg" alt="100 numbers"/>
  <img src="https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/test%20500.jpg" alt="500 numbers"/>
</p>

![Final grade](https://github.com/FPyMEHTAPIU/push_swap/blob/main/imgs/grade.png)
