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
class BinaryTree
{
public:
	//
	BinaryTree(const unsigned int value, const T &data, class BinaryTree<T> *parent)
	{
			m_parent = parent;
			m_value = value;
			m_data = data;
			m_leftChild = NULL;
			m_rightChild = NULL;
	}

	//
	~BinaryTree(void)
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
	bool AddLeftNode(unsigned int value, const T &data)
	{
		if (NULL != m_leftChild)
		{
			return false;
		}
		else
		{
			m_leftChild = new BinaryTree(value, data, this);
			return true;
		}
	}

	//
	bool AddRightNode(unsigned int value, const T &data)
	{
		if (NULL != m_rightChild)
		{
			return false;
		}
		else
		{
			m_rightChild = new BinaryTree(value, data, this);
			return true;
		}
	}

	//
    bool DeleteNode(unsigned int value);

	//
    bool findNode(unsigned int value, T &ref)
	{
		if (value == m_value)
		{
			ref = m_data;
			return true;
		}
		else 
		{
			if (NULL != m_leftChild)
			{
				if (!m_leftChild->findNode(value, ref))
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
			}
			else
			{
				return false;
			}
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
	BinaryTree<T> *GoLeftChild(void)
	{
		return m_leftChild;
	}

	//
	BinaryTree<T> *GoRightChild(void)
	{
		return m_rightChild;
	}

	//
	BinaryTree<T> *GoParent(void)
	{
		return m_parent;
	}
    

    
private:
	BinaryTree<T> *m_parent;
	BinaryTree<T> *m_leftChild;
	BinaryTree<T> *m_rightChild;
    
    unsigned int m_value;
    T m_data;
};


