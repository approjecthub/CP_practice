// https://leetcode.com/problems/word-ladder-ii/

import { Queue } from "@datastructures-js/queue";

function buildDistanceMap(
  beginWord: string,
  endWord: string,
  wordSet: Set<string>,
): Map<string, number> | null {
  if (!wordSet.has(endWord)) return null;

  const dist = new Map<string, number>();
  dist.set(beginWord, 0);

  const queue = new Queue<string>();
  queue.enqueue(beginWord);
  let foundEndWord = false;

  while (queue.size() > 0) {
    const word = queue.dequeue()!;
    if (word === endWord) {
      foundEndWord = true;
      break;
    }

    for (let i = 0; i < word.length; i++) {
      for (let j = 0; j < 26; j++) {
        const newChar = String.fromCharCode(97 + j);
        const newWord = word.slice(0, i) + newChar + word.slice(i + 1);
        if (wordSet.has(newWord) && !dist.has(newWord)) {
          dist.set(newWord, dist.get(word)! + 1);
          queue.enqueue(newWord);
        }
      }
    }
  }

  return foundEndWord ? dist : null;
}

function DFS(
  word: string,
  endWord: string,
  visited: Set<string>,
  dictionary: Set<string>,
  distMap: Map<string, number>,
  path: string[],
  result: string[][],
) {
  if (word === endWord) {
    result.push([...path]);
    return;
  }
  visited.add(word);

  for (let i = 0; i < word.length; i++) {
    for (let j = 0; j < 26; j++) {
      const newChar = String.fromCharCode(97 + j); // 97 is 'a'
      const newWord = word.slice(0, i) + newChar + word.slice(i + 1);

      if (
        dictionary.has(newWord) &&
        !visited.has(newWord) &&
        distMap.get(newWord) === distMap.get(word)! + 1
      ) {
        DFS(
          newWord,
          endWord,
          visited,
          dictionary,
          distMap,
          [...path, newWord],
          result,
        );
      }
    }
  }
  visited.delete(word);
}

function findLadders(
  beginWord: string,
  endWord: string,
  wordList: string[],
): string[][] {
  const dictionary = new Set(wordList);
  const dist = buildDistanceMap(beginWord, endWord, dictionary);

  if (!dist) return [];

  const result: string[][] = [];
  const visited = new Set<string>();
  DFS(beginWord, endWord, visited, dictionary, dist, [beginWord], result);
  return result;
}
