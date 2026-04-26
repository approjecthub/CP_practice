// https://leetcode.com/problems/word-ladder-ii/

import { Queue } from "@datastructures-js/queue";

function ladderLength(
    beginWord: string,
    endWord: string,
    dictionary: Set<string>,
  ): number {
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

function DFS(word: string, endWord: string, level: number, visited: Set<string>, dictionary: Set<string>, path: string[], result: string[][]) {
    if(level === 0 && word === endWord) {
        result.push([...path]);
        return;
    }
    else if(level === 0) {
        return;
    }
    visited.add(word);
    
    for (let i = 0; i < word.length; i++) {
        for (let j = 0; j < 26; j++) {
          const newChar = String.fromCharCode(97 + j); // 97 is 'a'
          const newWord = word.slice(0, i) + newChar + word.slice(i + 1);
  
          if (dictionary.has(newWord) && !visited.has(newWord)) {
            DFS(newWord, endWord, level - 1, visited, dictionary, [...path, newWord], result);
          }
        }
      }
    visited.delete(word);
}

function findLadders(beginWord: string, endWord: string, wordList: string[]): string[][] {
    const dictionary = new Set(wordList);
    const minmPathLen = ladderLength(beginWord, endWord, dictionary);
    if(minmPathLen === 0) return [];
    console.log("##### minmPathLen: ", minmPathLen);

    const result: string[][] = [];
    const visited = new Set<string>();
    DFS(beginWord, endWord, minmPathLen-1, visited, dictionary, [beginWord], result);
    return result;
};