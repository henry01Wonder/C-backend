<script setup>
import { ref } from 'vue';
let content = ref("");
let clearContent = function(){
    content.value = "";
};
let cssType = ref([]);

let color = ref({name: null, className: null});
let colorDn = ref(null);

</script>
<template>
    <nav>基本導覽列</nav>
    <main>
        <h3> 下拉式選單</h3>
        <select v-model="colorDn" >
            <option value="" >請選擇顏色</option>
            <option value="red">紅色</option>
            <option value="green">綠色</option>
            <option value="blue">藍色</option>
        </select>
        <div :class="colorDn">選擇的顏色是: {{colorDn}}</div>

<!--         
        <h3>單選框</h3>
        紅色<input type="radio" :value="{name: '紅色', className: 'red'}" v-model="color">
        綠色<input type="radio" :value="{name: '綠色', className: 'green' }" v-model="color">
        <div :class="color.className">選擇的顏色是: {{color.name}}</div>  -->


        <h3>多選框</h3>
        bold <input type="checkbox" value="bold" v-model="cssType">
        blue <input type="checkbox" value="blue" v-model="cssType">

        <div :class="cssType.join(' ')">cssType: {{ cssType }}</div>

        <h3>單行輸入框</h3>
        <input type="text" v-model="content">
        <div>使用者輸入的文字是{{content}}</div>
        <button @click="clearContent">清空輸入框</button>
        
        <h3>下拉式選單</h3>
        
 </main>
</template>
<style scope>
main {
    background-color: #dddddd;
}
.title{
    font-weight:bold
}
.hightlight{
    color:red
}
.red{
    color:red;
}
.green{
    color:green 
}
.blue{
    color:blue
}

.bold{
    font-weight:bold
}
</style>
