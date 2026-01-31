import io
import json
import os
import re
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
      body = "\n".join([
          i for i in map(lambda x : x.decode("utf-8"), content.splitlines())
          if not (
              i.startswith("#include \"") or
              i.startswith("#pragma once") or
              i.startswith("// ")
          )
      ]).strip()
      body = re.sub(r"\n{2,}", r"\n\n", body).split("\n")
      snippets[name] = {
          "prefix": f"ps-{name}",
          "body": body,
          "description": f"{name} snippet",
          "scope": "cpp"
      }

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
  json.dump(snippets, f, indent=2, ensure_ascii=False)

print(f"saved {len(snippets)} snippets")