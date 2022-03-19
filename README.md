### RHA ( Reverse Hash Algorithm )

RHA is a header-only hashing algorithm that could be used to store files on a server with a unique id , encrypting data or anything imaginable with a unique hash.

The algorithm does not have a decrypt function, being a 1-way hashing function.

``Some Simple Test``

C++ Code : 

```cpp
  cout << RHA::rha_encrypt("da") << endl;
```

Output on the first run :

``` 7c0ddcd7a57f29bfdd1ccbcddd43ff8f82bfe36442744 ```

Output on the second run : 

``` c33deaf7c12db40820846a8e2caabbb6459ff0119681016 ```

Output on the final run :

``` ceeae540283f476e9cb8075590c53cf344dfbb17059576 ```
