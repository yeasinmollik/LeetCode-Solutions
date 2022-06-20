### Trie
Intuition behind the solution is, if any word **s** is a suffix of another word **t**, cmpletely ignore **s** and add **t.size() + 1** to the answer. Or in other words, only consider those words which aren't a suffix of any other word.
​
But, how do we know if a word isn't a suffix of any other words? Simply reverse all words and insert them into a Trie. Words which aren't a suffix of any other word are sitting at the leaf node of this Trie! Now, simply add their total lengths(including '#').