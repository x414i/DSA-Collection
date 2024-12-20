void print_reversNode(node*& h) 
{
    node* _next = NULL;
    node* _prev = NULL;
    node* _curr = h;
    while (_curr != NULL)
    {
        _next = _curr->next;
        _curr->next = _prev;
        _prev = _curr;
        _curr = _next;
    }
    h = _prev;
    print(h);
}