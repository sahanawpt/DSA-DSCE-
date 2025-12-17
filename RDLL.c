#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

// Node structure
struct node {
int data;
struct node *prev;
struct node *next;
};

// Insert at end
struct node* insert_end(struct node *start, int data) {
struct node *temp, *curr;

temp = (struct node*)malloc(sizeof(struct node));
temp-&gt;data = data;
temp-&gt;prev = NULL;
temp-&gt;next = NULL;

if (start == NULL)
return temp;

curr = start;
while (curr-&gt;next != NULL)
curr = curr-&gt;next;

curr-&gt;next = temp;
temp-&gt;prev = curr;

return start;
}

// Display list (forward)
void display(struct node *start) {
struct node *curr = start;
while (curr != NULL) {
printf(&quot;%d &lt;-&gt; &quot;, curr-&gt;data);
curr = curr-&gt;next;
}
printf(&quot;NULL\n&quot;);
}

// Reverse DLL
struct node* reverse(struct node *start) {
struct node *curr = start, *temp = NULL;

while (curr != NULL) {
temp = curr-&gt;prev;
curr-&gt;prev = curr-&gt;next;
curr-&gt;next = temp;
curr = curr-&gt;prev; // move to next node (old next)
}

if (temp != NULL)
start = temp-&gt;prev;

return start;
}

// -------- Main Program --------
int main() {
struct node *start = NULL;

start = insert_end(start, 10);
start = insert_end(start, 20);
start = insert_end(start, 30);
start = insert_end(start, 40);

printf(&quot;Original DLL:\n&quot;);
display(start);

start = reverse(start);

printf(&quot;Reversed DLL:\n&quot;);
display(start);

return 0;
}