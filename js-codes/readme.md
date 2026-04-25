# Running TypeScript files

From this directory (`js-codes`):

1. **Direct (recommended)**

   ```bash
   npx tsx path/to/file.ts
   ```

   Example: `npx tsx LLD/ratelimit.ts`

2. **Via npm script**

   ```bash
   npm run ts -- path/to/file.ts
   ```

   The `--` is required so the file path is passed to `tsx`.

Prerequisite: `npm install` (installs `tsx` and `typescript`).

Node version: use the version in `.nvmrc` (e.g. `nvm use`).
