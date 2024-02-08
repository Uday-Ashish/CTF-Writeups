# needle in haystack 

## prompt - Sometimes find the flag is like finding a needle In a haystaCk, soMetimes all you need is a Push

from the promt  , if we look at the capitalized letters , there is a clue  - "ICMP"

by looking at the ICMP  stream ,

![ICMP](https://github.com/Uday-Ashish/CTF-Writeups/blob/main/BearcatCTF/forensics/needle_in_a_haystack/ICMP.png)

we get a encoded string, 516b4e4456455a375647687063306c7a5155356c5a5752735a58303d

after decoding it , we get the flag...
![2](https://github.com/Uday-Ashish/CTF-Writeups/blob/main/BearcatCTF/forensics/needle_in_a_haystack/2.png)

Flag - BCCTF{ThisIsANeedle} 



