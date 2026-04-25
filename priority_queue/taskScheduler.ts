// https://leetcode.com/problems/task-scheduler/

import {
  MaxPriorityQueue,
} from "@datastructures-js/priority-queue";
import { Queue } from "@datastructures-js/queue";

function leastInterval(tasks: string[], n: number): number {
  const umap: Map<string, number> = new Map();
  for (const task of tasks) {
    umap.set(task, (umap.get(task) || 0) + 1);
  }

  const pq = new MaxPriorityQueue<number>();
  const queue = new Queue<{ taskCount: number; scheduleTime: number }>();

  for (const [task, count] of umap) {
    pq.enqueue(count);
  }
  let time = 0;
  while (pq.size() > 0 || queue.size() > 0) {
    if (pq.size() > 0) {
      let taskCount = pq.dequeue();
      taskCount--;

      if (taskCount > 0) {
        queue.enqueue({ taskCount, scheduleTime: time + n });
      }
    }

    if (queue.size() > 0 && queue.front().scheduleTime === time) {
      let { taskCount } = queue.dequeue();
      if (taskCount > 0) {
        pq.enqueue(taskCount);
      }
    }
    time++;
  }

  return time;
}
