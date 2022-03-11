### RHA ( Reverse Hash Algorithm )

RHA is a header-only hashing algorithm that could be used to store files on a server with a unique id , encrypting data or anything imaginable with a unique hash.

The algorithm does not have a decrypt function, being a 1-way hashing function.

``Some Simple Test``

C++ Code : 

```cpp
  cout << RHA::rha_encrypt("da") << endl;
```

Output on the first run :

``` 289b587c9436368 ```

Output on the second run : 

``` 1697c98a19921100 ```

Output on the final run :

``` bec8d1087339020 ```
