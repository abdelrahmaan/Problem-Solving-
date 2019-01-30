What to know?
  1- When to use.
  2- Its Features.
  3- Its member Functions.
  4- How to initialize?
  5- How to iterate?
  6- How does it work?

- What if we want to store a user name and his ID? What if we want to sort an array of them?
- A Cartesian point.

Pair<T, T> p;
  - pair<int, int> p = {1, 7};
  - pair<int, int> p = make_pair(3, -2);
  - pair<string, int> p("Ali", 109);
  - pair<int, int> p = pair<int, int>(5, 7);
  - make_pair(f, s) ... {f, s}
  - first, second

Sequence containers:

-What if we don't know the size of the array -Not Even the exact maximum- ?
vector<T> v;
  Features:
    - Opened from the back.
    - Dynamic size.
    - Constant access time.
    - [] operator.
  Initialization:
    - vector<int> v(size);       //initialized by Zeros
    - vector<int> v(size, val);
    - vector<int> v2(v1);
    - vector<int> v2(begin, end);
    - vector<int> v = vector<int>();
  Commonly used Member functions:
    - begin()
    - end()
    - rbegin()
    - rend()
    - resize(size)
    - reserve(capacity)  **
    - size()
    - empty()
    - push_back(val)
    - pop_back()
    - back()
    - front()
    - insert(it, val)    ---   insert(it, begin, end)
    - erase(it)    ---   erase(begin, end)
    - clear()
  Iteration:
    for(int i = 0 ; i < n ; ++i){
      scanf("%d", &x);
      v.push_back(x);
    }
    for(int i = 0 ; i < n ; ++i)
      printf("%d ", v[i]);
    for(int x : v)
      printf("%d ", x);
    for(auto x = v.begin() ; x!=v.end() ; ++x)
      printf("%d ", *x);

-What if we want to insert in the beginning?
deque<T> dq;
  Features:
    - Opened from both ends.
    - Dynamic size.
    - Constant access time.
    - [] operator.
  Initialization:
    - deque<int> dq(size);       //initialized by Zeros
    - deque<int> dq(size, val);
    - deque<int> dq2(dq1);
    - deque<int> dq2(begin, end);
    - deque<int> dq = deque<int>();
  Commonly used Member functions:
    - begin()
    - end()
    - rbegin()
    - rend()
    - resize(size)
    - size()
    - empty()
    - push_back(val)
    - pop_back()
    - back()
    - push_front(val)
    - pop_front()
    - front()
    - insert(it, val)    ---   insert(it, begin, end)
    - erase(it)    ---   erase(begin, end)
    - clear()
  Iteration:
    for(int i = 0 ; i < n ; ++i){
      scanf("%d", &x);
      dq.push_back(x);
    }
    for(int i = 0 ; i < n ; ++i)
      printf("%d ", dq[i]);
    for(int x : dq)
      printf("%d ", x);
    for(auto x = dq.begin() ; x!=dq.end() ; ++x)
      printf("%d ", *x);

list<T> l;
  Features:
    - Constant insertion time.
    - Dynamic size.
  Initialization:
    - list<int> l(size);       //initialized by Zeros
    - list<int> l(size, val);
    - list<int> l2(l1);
    - list<int> l2(begin, end);
    - list<int> l = list<int>();
  Commonly used Member functions:
    - begin()
    - end()
    - rbegin()
    - rend()
    - resize(size)
    - size()
    - empty()
    - push_back(val)
    - pop_back()
    - back()
    - push_front(val)
    - pop_front()
    - front()
    - insert(it, val)    ---   insert(it, begin, end)
    - erase(it)    ---   erase(begin, end)
    - clear()
    - sort()
    - splice(it, list)      ---     splice(it, list, begin, end)    //Cut and paste
    - remove(val)
    - merge(list)      //Merges sorted lists
    - unique()
  Iteration:
    for(int i = 0 ; i < n ; ++i){
      scanf("%d", &x);
      l.push_back(x);
    }
    for(int x : l)
      printf("%d ", x);
    for(auto x = l.begin() ; x!=l.end() ; ++x)
      printf("%d ", *x);

Container Adapters:
  stack<T> st;    //LIFO
  Features:
    - deque with some restrictions.
    - Last in first out.
  Commonly used Member functions:
    - size()
    - empty()
    - push(val)
    - pop()   //Avoid RTE
    - top()   //Avoid RTE
  Iteration:
    while(!st.empty()){
      printf("%d ", st.top());
      st.pop();
    }

  queue<T> q;    //FIFO
  Features:
    - deque with some restrictions.
    - First in first out.
  Commonly used Member functions:
    - size()
    - empty()
    - push(val)
    - pop()     //Avoid RTE
    - front()   //Avoid RTE
  Iteration:
    while(!q.empty()){
      printf("%d ", q.front());
      q.pop();
    }

  priority_queue<T> pq;    //FIFO
  Features:
    - Max heap tree.
  Commonly used Member functions:
    - size()
    - empty()
    - push(val)
    - pop()     //Avoid RTE
    - top()   //Avoid RTE
  Iteration:
    while(!pq.empty()){
      printf("%d ", pq.top());
      pq.pop();
    }