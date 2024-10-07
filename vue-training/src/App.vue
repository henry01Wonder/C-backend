<script setup>
// 產品資料串接
// 評論資料串接
// 建立一個標籤選單做內容切換
import { ref } from 'vue';
import ProductPage from "./product/ProductPage.vue";
import ReviewPage from "./review/ReviewPage.vue";
let page = ref("product"); // 紀錄一個 page 的響應式狀態, 用來決定要看的是 product or review, default product
let change = function (clickPage) {
    page.value = clickPage;
}
</script>
<template>
    <nav>
        <span :class="page === 'product' ? 'current' : ''" @click="change('product')"> 產品資料</span>
        <span :class="page === 'review' ? 'current' : ''" @click="change('review')"> 評論訊息</span>
    </nav>
    <main>
        <ProductPage v-if="page === 'product'" />
        <ReviewPage v-if="page === 'review'" />
    </main>

</template>

<style scoped>
nav {
    font-size: 20px;
}

nav>span {
    margin-right: 10px;
}

nav>span.current {
    font-weight: bold;
}
</style>