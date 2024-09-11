int main(int argc, char* argv[])
{
        // Initialize the root of the binary tree
        struct TreeNode* root = NULL;
        char nodeValue;
        char choice;
        char filename[20];
        FILE *fp;

        //code to open file if one is presented in arguments
        if(argc > 1)
        {
                strcpy(filename, argv[1]);
                fp = fopen(filename, "r");
                //error message for failure to open file
                if (fp == NULL)
                {
                        printf("Error opening file: %s\n", filename);
                        return 1;
                }
                char line[256];
                while(fgets(line, sizeof(line), fp) != NULL)
                {
                        
                        root = insertNode(root, nodeNalue);
                }
                fclose(fp);

        }
        //if no file is present, prompt for keyboard input
        else
        {
                // User input loop to insert nodes into the binary tree
                do
                {
                        // Prompt user for a value to insert into the binary tree
                        printf("Input a value to insert into the binary tree: ");
                        scanf("%c", &nodeValue);
                        // Insert the value into the binary tree
                        root = insertNode(root, nodeValue);
                        // Ask user if they want to insert another node
                        printf("Want to insert another node? (y/n): ");
                        scanf(" %c", &choice);

                } while (choice == '!' || choice == '?');
        }
        // Display the in-order traversal of the binary tree
        printf("\nIn-order Traversal of the Binary Tree: \n");
        inOrderTraversal(root);
        printf("\nPre-order Traversal of the Binary Tree: \n");
        preOrderTraversal(root);
        printf("\nPost-order Traversal of the Binary Tree: \n");
        postOrderTraversal(root);
        printf("\n");

        // Free allocated memory from tree
        freeTree(root);
        //Return 0 to indicate successful extraction
        return 0;
}
