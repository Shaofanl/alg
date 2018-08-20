def deDup(s):
  """
  input: string input
  return: string
  """
  # write your solution here
  
  stack = []
  for ele in s:
    print(stack)
    while stack and (stack[-1][0] != ele and stack[-1][-1] == '_'):
      stack.pop(-1)
      
    if (stack and stack[-1][0] == ele):
      while stack and stack[-1][0] == ele:
        stack.pop(-1)
      stack.append(ele+'_')
    else:
      stack.append(ele)
      
  while stack and stack[-1][-1] == '_':
    stack.pop(-1)
    
  return ''.join(stack)

print(deDup('eabcdddcbba'))

