### RHA ( Reverse Hash Algorithm )

RHA is a header-only encryption algorithm that could be used to store files on a server with a unique id , encrypting data or anything imaginable with a unique hash.

The algorithm does not have a decrypt function, being a 1-way encryption function.

``Some Simple Test``

```cpp
  cout << RHA::rha_encrypt("da") << endl;
```
