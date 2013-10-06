template<typename _BidirectionalIterator>
    bool
next_permutation(_BidirectionalIterator __first,
        _BidirectionalIterator __last)
{
    // concept requirements
    __glibcxx_function_requires(_BidirectionalIteratorConcept<
            _BidirectionalIterator>)
        __glibcxx_function_requires(_LessThanComparableConcept<
                typename iterator_traits<_BidirectionalIterator>::value_type>)
        __glibcxx_requires_valid_range(__first, __last);

    if (__first == __last)
        return false;
    _BidirectionalIterator __i = __first;
    ++__i;
    if (__i == __last)
        return false;
    __i = __last;
    --__i;

    for(;;) {
        _BidirectionalIterator __ii = __i;
        --__i;
        if (*__i < *__ii)
        {
            _BidirectionalIterator __j = __last;
            while (!(*__i < *--__j))
            {}
            std::iter_swap(__i, __j);
            std::reverse(__ii, __last);
            return true;
        }
        if (__i == __first)
        {
            std::reverse(__first, __last);
            return false;
        }
    }
}
