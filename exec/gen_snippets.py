import os
import json

TEMPLATE_FOLDER = "./ps/template"
OUTPUT_FILE = "./.vscode/ps.code-snippets"

snippets = {}

for root, dirs, files in os.walk(TEMPLATE_FOLDER):
  for filename in files:
    if filename.endswith(".cpp"):
      filepath = os.path.join(root, filename)
      with open(filepath, "r", encoding="utf-8") as f:
        content = f.read()
      body = content.splitlines()
      name = filename
      snippets[name] = {
        "prefix": name,
        "body": body,
        "description": f"{name} template"
      }

with open(OUTPUT_FILE, "w", encoding="utf-8") as f:
  json.dump(snippets, f, indent=2, ensure_ascii=False)

print(f"saved {len(snippets)} templates")