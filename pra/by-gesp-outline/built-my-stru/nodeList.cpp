#include <iostream>

using namespace std;

template <class T>
class CNode{
    public:
    CNode<T> *m_pNext;
    T m_Data;
    CNode<T>(){
        m_pNext = nullptr;
    }
};

template <class T>
class CList{
    private:
    CNode<T> *m_pHeader;
    int m_NodeSum;
    
    public:
    CList(){
        m_pHeader = nullptr;
        m_NodeSum = 0;
    }
    CNode<T> *MoveTrail(){
        CNode<T> *pTmp = m_Header;
        for(int i = 1 ; i < m_NodeSum;++i){
            pTmp = pTmp -> m_pNext;
        }
        return pTmp;
    }
    void AddNode(CNode<T> *pNode){
        if (m_NodeSum == 0){
            m_pHeader = pNode;
        }
        else{
            CNode<T> *pTrail = MoveTrail;
            pTrail -> m_pNext = pNode;
        }
        ++m_NodeSum; 
    }
    void PassList(){
        if(m_NodeSum > 0){
            CNode<T> *tTmp = m_Header;
            cout << pTmp -> m_Data << endl;
            for(int i = 1;i < m_NodeSum;++i){
                pTmp = pTmp -> m_pNext;
                cout << pTmp -> m_Data;
            }
        }
    }
    ~CList(){
        if(m_NodeSum > 0){
            CNode<T> *pDelete = m_pHeader;
            CNode<T> *pTmp = nullptr;
            for(int i = 0,i < m_NodeSum;++i){
                pTmp = pDelete -> m_pNext;
                delete pDelete;
                pDelete = pTmp;
            }
            m_NodeSum = 0;
            pDelete = nullptr;
            pTmp = nullptr;
        }
        m_pHeader = nullptr;
    }
};

void main(){
    CList<int> list;
    for(int i = 0; i<5;++i){
        CNode<int> *pNode = new CNode<int>();
        pNode -> m_Data = i;
        list.AddNode(pNode);
    }
    list.PassList();
    cout << endl;

}