import os
dir = os.listdir("/home/tushar55/Downloads")
rm = [x for x in dir if x.startswith("testCase")]
for r in rm:
  print(r, type(r))
  path = f"/home/tushar55/Downloads/'{r}'"
  print(path)
  os.system(f"rm {path}")