<script setup>
import { onMounted, ref } from 'vue';
import ReviewList from './ReviewList.vue';
let reviews = ref(null);


onMounted(async () => {
    let response = await fetch("https://cwpeng.github.io/live-records-samples/data/reviews.json");
    let data = await response.json();
    reviews.value = data;
    console.log(data);
})
</script>

<template>
    <div v-if="reviews === null">載入中...</div>
    <ReviewList v-else :reviews="reviews" />
</template>

<style scoped></style>