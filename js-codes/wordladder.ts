// https://leetcode.com/problems/word-ladder/

import { Queue } from "@datastructures-js/queue";

function ladderLength(
  beginWord: string,
  endWord: string,
  wordList: string[],
): number {
  const dictionary = new Set(wordList);
  if (!dictionary.has(endWord)) return 0;

  const queue = new Queue<{ word: string; level: number }>();
  queue.enqueue({ word: beginWord, level: 1 });
  const visited = new Set<string>();
  visited.add(beginWord);

  while (queue.size() > 0) {
    const { word, level } = queue.dequeue()!;
    if (word === endWord) return level;

    for (let i = 0; i < word.length; i++) {
      for (let j = 0; j < 26; j++) {
        const newChar = String.fromCharCode(97 + j); // 97 is 'a'
        const newWord = word.slice(0, i) + newChar + word.slice(i + 1);

        if (dictionary.has(newWord) && !visited.has(newWord)) {
          visited.add(newWord);
          queue.enqueue({ word: newWord, level: level + 1 });
        }
      }
    }
  }
  return 0;
}
