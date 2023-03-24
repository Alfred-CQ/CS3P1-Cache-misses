# CS3P1-Cache-misses
Execution of matrix multiplication algorithms using the valgrind and kcachegrind tools to evaluate their performance in terms of cache misses.

### Compile the project

To compile the project run (make sure you've got one version of g++ installed before) the following comands:

```
$ make all
$ bin/main
```

### Evaluating performance

Classical matrix multiplication, the three-loop nested version, was implemented and its performance was evaluated considering different matrix sizes.

![Classic multiplication](https://i.ibb.co/HPd9RwK/Screenshot-20230322-140135.png)

The block version, six nested blocks, was implemented and its performance was evaluated with a block size of 50 and considering different matrix sizes.

![Block multiplication](https://i.ibb.co/CmbMmnn/Screenshot-20230322-191822.png)

### Performance comparison

Comparison of the performance of both matrix multiplications

First, 3 repetitions were carried out and the following averages were obtained

| Input Size | Classic Multiplication (ms) | Block Multiplication (ms) |
| --- | --- | --- |
| 100 | 4,363 | 8,206 |
| 200 | 38,138 | 45,606 |
| 300 | 130,860 | 127,997 |
| 400 | 300,613 | 290,762 |
| 500 | 612,546 | 559,705 |
| 600 | 1104,899 | 956,649 |
| 700 | 1781,877 | 1513,623 |
| 800 | 2750,773 | 2247,443 |
| 900 | 3928,047 | 3424,177 |
| 1000 | 7569,983 | 4750,353 | |

Finally, the results are plotted to obtain a graph that indicates: with inputs less than or equal to 200 the classical multiplication performs well, the point where both methods balance is for an input of 300 and for inputs greater than 400 the block multiplication, with block size = 50, outperforms classical multiplication. 

![Performance comparison](https://i.ibb.co/NWq57k9/Performance-Comparison.png)
