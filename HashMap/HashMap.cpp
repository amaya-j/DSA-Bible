#include<vector>
#include<iostream>
using namespace std;

template <typename K, typename V>
struct Node
{
    K key;
    V val;

    Node* next= nullptr;

    Node(K k, V v): key(k), val(v), next(nullptr)
};
template <typename K, typename V>
class HashMap
{
    private:
        int cap;
        int size;
        vector<Node<K,V>*> buckets;
        int hashKey(const K& key)
        {
            return hash<K>{}(key)%cap;
        }
    public:
        HashMap(int capacity=8): cap(capacity), size(0)
        {
            buckets.resize(cap, nullptr);
        }

        void put(const K& key, const V& val)
        {
            int idx= hashKey(key);

            Node<K,V>* curr= buckets[idx];

            while(curr)
            {
                if(curr->key==key)
                {
                    curr->val= val;
                    return
                }
                curr= curr->next;
            }
            Node<K,V>* newNode= new Node<K,V>(key,value);
            newNode->next= buckets[idx];
            buckets[idex]= newNode;
            size++;
        }

        bool get(const K& key, V& res)
        {
            int idx= hashKey(key);
            
            Node<K,V>* curr= buckets[idx];

            while(curr)
            {
                if (curr->key==key)
                {
                    res= curr->val;
                    return true;
                }
                curr= curr->next;
            }
            return false;
        }

        void remove(const K& key)
        {
            int idx= hashKey(key);
            Node<V,K>* curr= buckets[idx];
            Node<V,K>* prev= nullptr;

            while (curr)
            {
                if (curr->key==key)
                {
                    if (prev)
                    {
                        prev->next= curr->next;
                    }
                    else buckets[idx]= curr->next;
                    delete curr;
                    size--;
                    return;
                }
                prev= curr;
                curr=curr->next;
            }
        }

        float loadfactor()
        {
            return size/cap;
        }
};