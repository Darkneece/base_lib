// heap.h

#include "btree.h"

template <typename T>
class Heap
{
public:
	Heap()
	{
		m_root = NULL;
	}

	~Heap()
	{
		if (m_root != NULL)
		{
			delete m_root;
		}
	}

	//
	BuildHeap(const int inputArray[], const int length)
	{
		T data;

		if (m_root != NULL)
		{
			delete m_root;
		}

		m_root = new BinaryTree<T>(inputArray[0], T, NULL);

		for (int i = 0; i < length; i++)
		{
			BinaryTree<T> *current = m_root;
			if (inputArray[i] >= current->GetValue())
			{
				BinaryTree<T> *leftChild = current->GoLeftChild();
				if (NULL == leftChild)
				{
					current->AddLeftNode(inputArray[i], data);
				}
				else if (NULL == rightChild)
				{
					current->AddRightNode(inputArray[i], data);
				}
				else
				{
					current = current->GoLeftChild();
				}
				
			}
		}
	}


	bool Insert();
	bool DeleteMin();

	T FindMin()
	{
		return m_root->GetData();
	}
private:
	BinaryTree<T> *m_root;
};

