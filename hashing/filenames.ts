// https://leetcode.com/problems/making-file-names-unique/description/

function getFolderNames(names: string[]): string[] {
    const umap: Map<string, number> = new Map();
    const ans: string[] = []

    for(const name of names){
        if(!umap.has(name)){
            umap.set(name, 0);
            ans.push(name);
        }
        else{
            let k = umap.get(name)! + 1;
            while(umap.has(name + `(${k})`)){
                k++;
            }
            umap.set(name, k);
            ans.push(name + `(${k})`);
            umap.set(name + `(${k})`, 0);
        }
    }
    return ans;
};