/*
 * BST.hxx
 * 
 * Copyright 2014 Darkneece <darkneece@darkneece-900>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


template <typename T>
class BinarySearchTree
{
public:
	//
	BinarySearchTree(const unsigned int value, const T &data, class BinaryTree<T> *parent)
	{
			m_parent = parent;
			m_value = value;
			m_data = data;
			m_leftChild = NULL;
			m_rightChild = NULL;
	}

	//
	~BinarySearchTree(void)
	{
		if (NULL != m_leftChild)
		{
			delete m_leftChild;
		}

		if (NULL != m_rightChild)
		{
			delete m_rightChild;
		}
	}

    //
    bool AddNode(unsigned int value, const T &data)
	{
		if (value < m_value)
		{
			if (NULL != m_leftChild)
			{
				m_leftChild->AddNode(value, data);
			}
			else
			{
				m_leftChild = new BinaryTree(value, data, this);
			}
		}
		else if (value > m_value)
		{
			if (NULL != m_rightChild)
			{
				m_rightChild->AddNode(value, data);
			}
			else
			{
				m_rightChild = new BinaryTree(value, data, this);
			}
		}
		else
		{
			m_data = data;
		}

		return true;
	}

	//
	bool DeleteNode(unsigned int value)
	{

	}

	//
    bool findNode(unsigned int value, T &ref)
	{
		if (value < m_value)
		{
			if (NULL != m_leftChild)
			{
				return m_leftChild->findNode(value, ref);
			}
			else
			{
				return false;
			}
		}
		else if (value > m_value)
		{
			if (NULL != m_rightChild)
			{
				return m_rightChild->findNode(value, ref);
			}
			else
			{
				return false;
			}
		}
		else
		{
			ref = m_data;
			return true;
		}
	}

    
    void PreTraverse(void)
	{
		if (NULL != m_leftChild)
		{
			m_leftChild->PreTraverse();
		}

		if (NULL != m_rightChild)
		{
			m_rightChild->PreTraverse();
		}
	}

	//
    void InTraverse(void)
	{
		if (NULL != m_leftChild)
		{
			m_leftChild->InTraverse();
		}

		if (NULL != m_rightChild)
		{
			m_rightChild->InTraverse();
		}
	}

	//
    void PostTraverse(void)
	{
		if (NULL != m_leftChild)
		{
			m_leftChild->PostTraverse();
		}

		if (NULL != m_rightChild)
		{
			m_rightChild->PostTraverse();
		}
	}
    
	//
    int GetValue(void)
	{
		return m_value;
	}

	//
    int GetData(T &ref);
    
	//
	BinarySearchTree<T> *GoLeftChild(void)
	{
		return m_leftChild;
	}

	//
	BinarySearchTree<T> *GoRightChild(void)
	{
		return m_rightChild;
	}

	//
	BinarySearchTree<T> *GoParent(void)
	{
		return m_parent;
	}
    

    
private:
	BinarySearchTree<T> *m_parent;
	BinarySearchTree<T> *m_leftChild;
	BinarySearchTree<T> *m_rightChild;
    
    unsigned int m_value;
    T m_data;
};


