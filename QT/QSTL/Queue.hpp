#ifndef QUEUE_HPP
#define QUEUE_HPP
#include<QQueue>
#include<QStack>

void QueueMain()
{
    QStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    while(!stack.isEmpty())
    {
        qDebug(" %d ",stack.pop());
    }

    QQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    while(!queue.isEmpty())
    {
        qDebug(" %d ",queue.dequeue());
    }
}


#endif // QUEUE_HPP
