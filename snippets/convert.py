import os
import json
import argparse
import re


def to_snippet_name(path, root):
    """
    Derive a human-readable snippet name from file path relative to root.
    e.g. 'templates/fenwick.cpp' -> 'Fenwick'
    """
    rel = os.path.relpath(path, root)
    base = os.path.splitext(rel)[0]
    parts = re.split(r'[\\/._\\-]+', base)
    name = ' '.join(p.capitalize() for p in parts if p)
    return name


def to_prefix(path):
    """
    Use the filename (without extension) as the snippet prefix, lowercased.
    e.g. 'fenwick.cpp' -> 'fenwick'
    """
    base = os.path.splitext(os.path.basename(path))[0]
    return base.lower()


def gather_templates(root_dir, exts=None):
    """
    Walk root_dir, read files matching exts (list of extensions or None),
    and build a dict of snippet entries.
    """
    snippets = {}
    for dirpath, _, filenames in os.walk(root_dir):
        for fname in filenames:
            if exts and not any(fname.endswith(ext) for ext in exts):
                continue
            fullpath = os.path.join(dirpath, fname)
            try:
                with open(fullpath, 'r', encoding='utf-8') as f:
                    lines = f.read().splitlines()
            except Exception:
                # skip unreadable files
                continue

            name = to_snippet_name(fullpath, root_dir)
            prefix = to_prefix(fullpath)
            snippets[name] = {
                "prefix": prefix,
                "body": lines,
                "description": f"Snippet for {name}"  
            }
    return snippets


def main():
    parser = argparse.ArgumentParser(
        description="Generate VSCode-style JSON snippets from a templates folder"
    )
    parser.add_argument(
        "-r", "--root",
        help="Root templates directory",
        default=os.path.expanduser("~/competitve-programming/lib/dsa")
    )
    parser.add_argument(
        "-o", "--outfile",
        help="Output JSON file, e.g. '~/competitve-programming/snippets/cpp.json'",
        default=os.path.expanduser("~/competitve-programming/snippets/cpp.json")
    )
    parser.add_argument(
        "--exts",
        help="Comma-separated list of file extensions to include (e.g. .cpp,.h)",
        default=".cpp,.h"
    )
    args = parser.parse_args()

    exts = [e.strip() for e in args.exts.split(',') if e.strip()]
    snippets = gather_templates(args.root, exts=exts)

    outdir = os.path.dirname(args.outfile)
    os.makedirs(outdir, exist_ok=True)
    with open(args.outfile, 'w', encoding='utf-8') as out:
        json.dump(snippets, out, indent=2)

    print(f"Generated {len(snippets)} snippets → {args.outfile}")


if __name__ == "__main__":
    main()
