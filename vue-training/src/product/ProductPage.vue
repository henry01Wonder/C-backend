<script setup>
import {onMounted,ref} from 'vue';
import ProductList from './ProductList.vue';
let products = ref(null);

// 組件掛載完成後, 開始呼叫 fetch 串接後端的資料
onMounted(async() => {
    let response = await fetch("https://cwpeng.github.io/live-records-samples/data/products.json");
    let data = await response.json();
    products.value = data;
    console.log(data);

});
</script>
<template>
<div v-if="products==null">載入中...</div>
<ProductList v-else :products="products"/>

</template>

<style scoped>
</style>