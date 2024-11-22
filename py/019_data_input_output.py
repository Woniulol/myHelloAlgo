"""
BufferReader: Reduce disk IO frequency.

StreamTokenizer: Pass BufferReader to construct StreamTokenizer. Ignore all the space and enter to get the individual data from memory.

PrintWriter: Memory space for the output answer. Not using IO due to low efficiency.
Equivalent to store all the answers to the memory space and push all the answer to validator in the end. Thus there is only one IO operation.
"""
