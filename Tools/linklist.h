

template <typename T>
class LinkList
{
public:
	// Construcor
	LinkList()
	{
		m_head = NULL;
	}

	// 
	~LinkList()
	{
		if (NULL != m_head)
		{
			delete m_head;
		}
	}

	//addNode
	bool addNode(const T &data)
	{
		if (m_head == NULL)
		{
			m_head = new Node(data);
		}
		else
		{
			struct Node *tail = m_head;

			while (tail->m_next != NULL)
			{
				tail = tail->m_next;
			}

			tail->m_next = new Node(data);
		}

		return true;
	}

	//deleteNode
	bool deleteNode()
	{
		return false;
	}

	//GetNode
	bool GetNode(const int index, T &data)
	{
		struct Node *cur = m_head;
		for (int i = 0; i < index; i++)
		{
			if (NULL == cur)
			{
				return false;
			}
			cur = cur->m_next;
		}

		data = cur->m_data;
		return true;
	}

	//Reverse
	void Reverse()
	{

	}

	//Reverse
	void Reverse(const int k)
	{

	}

private:
    struct Node
    {
        Node(const T &data)
        {
            m_data = data;
            m_next = NULL;
        }
        
        ~Node()
        {
            if (NULL != m_next)
            {
                delete m_next;
            }
        }
        
        T m_data;
        struct Node *m_next;
    };

    struct Node *m_head;
};