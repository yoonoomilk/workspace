import io
import json
import os
import zipfile

import requests

REPO_URL = "https://github.com/yoonoomilk/ps/archive/refs/heads/main.zip"
OUTPUT_FILE = "./.vscode/ps-snippets.code-snippets"

snippets = {}

response = requests.get(REPO_URL)
response.raise_for_status()

with zipfile.ZipFile(io.BytesIO(response.content)) as z:
  for fileinfo in z.filelist:
    file = fileinfo.filename
    if file.startswith("ps-main/snippets/") and file.endswith(".cpp"):
      name, ext = os.path.splitext(os.path.basename(file))
      with z.open(file) as f:
        content = f.read()
      body = [
          i.decode("utf-8")
          for i in content.splitlines()
          if not (
              i.decode("utf-8").startswith("#include \"") or
              i.decode("utf-8").startswith("#pragma once")
          )
      ]
      if body[0] == "":
        body.pop(0)
      snippets[name] = {
          "prefix": f"ps-{name}",
          "body": body,
          "description": f"{name} snippet",
          "scope": "cpp"
      }

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
  json.dump(snippets, f, indent=2, ensure_ascii=False)

print(f"saved {len(snippets)} snippets")